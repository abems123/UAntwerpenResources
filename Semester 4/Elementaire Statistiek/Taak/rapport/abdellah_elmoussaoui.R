studentennummer <- 20246031
alpha <- 0.01

sneeuw <- read.csv("Sneeuw.csv", row.names = 1)
set.seed(studentennummer); my_sneeuw_index <- sample(1:5000, 500)
my_sneeuw <- sneeuw[my_sneeuw_index, ]

temp <- read.csv("Temperatuur.csv", row.names = 1)
set.seed(studentennummer); my_temp_index <- sample(1:4500, 250)
my_temp <- temp[my_temp_index, ]

wind <- read.csv("Wind.csv", row.names = 1)
set.seed(studentennummer); my_wind_index <- sample(1:605, 600)
my_wind <- wind[my_wind_index, , drop = FALSE]

dir.create("figuren", showWarnings = FALSE)
sink("project_output.txt", split = TRUE)

cat("Project Elementaire Statistiek\n")
cat("Studentennummer:", studentennummer, "\n")
cat("Significantieniveau alpha =", alpha, "\n\n")

# ============================================================
# 1. Sneeuwcondities: globale chi-kwadraattoets
# ============================================================
cat("==================== 1. Sneeuwcondities ====================\n")

sneeuw_tabel <- xtabs(~ temperatuurklasse + sneeuwtype + lawine_alarm,
                      data = my_sneeuw)
cat("Waargenomen frequenties:\n")
print(sneeuw_tabel)

N <- sum(sneeuw_tabel)
p_temp <- prop.table(margin.table(sneeuw_tabel, 1))
p_sneeuw <- prop.table(margin.table(sneeuw_tabel, 2))
p_alarm <- prop.table(margin.table(sneeuw_tabel, 3))

verwacht <- array(0, dim = dim(sneeuw_tabel), dimnames = dimnames(sneeuw_tabel))
for (i in seq_along(p_temp)) {
  for (j in seq_along(p_sneeuw)) {
    for (k in seq_along(p_alarm)) {
      verwacht[i, j, k] <- N * p_temp[i] * p_sneeuw[j] * p_alarm[k]
    }
  }
}

cat("\nVerwachte frequenties onder volledige onderlinge onafhankelijkheid:\n")
print(round(verwacht, 2))

chi2_waarde <- sum((sneeuw_tabel - verwacht)^2 / verwacht)
vrijheidsgraden <- prod(dim(sneeuw_tabel)) - sum(dim(sneeuw_tabel)) + length(dim(sneeuw_tabel)) - 1
p_waarde_sneeuw <- pchisq(chi2_waarde, df = vrijheidsgraden, lower.tail = FALSE)
kritieke_waarde <- qchisq(1 - alpha, df = vrijheidsgraden)

cat("\nChi-kwadraat teststatistiek:", chi2_waarde, "\n")
cat("Vrijheidsgraden:", vrijheidsgraden, "\n")
cat("Kritieke waarde op 1%:", kritieke_waarde, "\n")
cat("p-waarde:", p_waarde_sneeuw, "\n")
cat("Minimale verwachte frequentie:", min(verwacht), "\n")
if (p_waarde_sneeuw < alpha) {
  cat("Besluit: H0 wordt verworpen op 1%. De drie variabelen lijken niet volledig onderling onafhankelijk.\n\n")
} else {
  cat("Besluit: H0 wordt niet verworpen op 1%. Er is geen duidelijk bewijs voor onderlinge afhankelijkheid.\n\n")
}

png("figuren/sneeuw_waargenomen_verwacht.png", width = 1100, height = 700)
labels <- paste(rep(dimnames(sneeuw_tabel)[[1]], each = 4),
                rep(rep(dimnames(sneeuw_tabel)[[2]], each = 2), times = 3),
                rep(dimnames(sneeuw_tabel)[[3]], times = 6),
                sep = "\n")
barplot(rbind(as.vector(sneeuw_tabel), as.vector(verwacht)), beside = TRUE,
        names.arg = labels, las = 2, cex.names = 0.7,
        ylab = "Frequentie",
        main = "Waargenomen en verwachte frequenties")
legend("topright", legend = c("waargenomen", "verwacht"), fill = c("gray40", "gray80"))
dev.off()

# ============================================================
# 2. Temperatuur: lineaire regressie met twee verklarende variabelen
# ============================================================
cat("==================== 2. Temperatuur ====================\n")

cat("Samenvatting van my_temp:\n")
print(summary(my_temp))

cat("\nCorrelatiematrix:\n")
print(cor(my_temp))

model_temp <- lm(Temperatuur ~ Hoogte + Afstand_tot_vallei, data = my_temp)
model_null <- lm(Temperatuur ~ 1, data = my_temp)

cat("\nRegressiemodel:\n")
print(summary(model_temp))

cat("\nVergelijking met nulmodel via globale F-test:\n")
print(anova(model_null, model_temp))

r2 <- summary(model_temp)$r.squared
adj_r2 <- summary(model_temp)$adj.r.squared
resid_sd <- summary(model_temp)$sigma
rmse <- sqrt(mean(residuals(model_temp)^2))
mae <- mean(abs(residuals(model_temp)))

cat("\nR-kwadraat:", r2, "\n")
cat("Aangepaste R-kwadraat:", adj_r2, "\n")
cat("Residual standard error:", resid_sd, "\n")
cat("RMSE op de steekproef:", rmse, "\n")
cat("MAE op de steekproef:", mae, "\n")
cat("99% betrouwbaarheidsintervallen voor de coefficienten:\n")
print(confint(model_temp, level = 0.99))

png("figuren/temperatuur_verkenning.png", width = 1100, height = 800)
par(mfrow = c(2, 2))
plot(my_temp$Hoogte, my_temp$Temperatuur,
     xlab = "Hoogte (m)", ylab = "Temperatuur (°C)",
     main = "Temperatuur tegenover hoogte")
plot(my_temp$Afstand_tot_vallei, my_temp$Temperatuur,
     xlab = "Afstand tot vallei (km)", ylab = "Temperatuur (°C)",
     main = "Temperatuur tegenover afstand")
plot(fitted(model_temp), residuals(model_temp),
     xlab = "Voorspelde temperatuur", ylab = "Residuen",
     main = "Residuen tegenover voorspelde waarden")
abline(h = 0, lty = 2)
qqnorm(residuals(model_temp), main = "QQ-plot residuen")
qqline(residuals(model_temp))
par(mfrow = c(1, 1))
dev.off()

png("figuren/temperatuur_voorspeld_observeerd.png", width = 800, height = 700)
plot(fitted(model_temp), my_temp$Temperatuur,
     xlab = "Voorspelde temperatuur (°C)",
     ylab = "Gemeten temperatuur (°C)",
     main = "Voorspelde tegenover gemeten temperatuur")
abline(a = 0, b = 1, lty = 2)
dev.off()

# ============================================================
# 3. Wind: eenzijdige t-test voor het gemiddelde
# ============================================================
cat("==================== 3. Wind ====================\n")

windsnelheid <- my_wind$Wind
cat("Samenvatting windsnelheid:\n")
print(summary(windsnelheid))
cat("Standaardafwijking:", sd(windsnelheid), "\n")
cat("Aantal observaties:", length(windsnelheid), "\n")
cat("Grootste 10 waarden:\n")
print(sort(windsnelheid, decreasing = TRUE)[1:10])

mu0 <- 11.7
n_wind <- length(windsnelheid)
test_waarde_wind <- (mean(windsnelheid) - mu0) / (sd(windsnelheid) / sqrt(n_wind))
p_waarde_wind <- pt(test_waarde_wind, df = n_wind - 1, lower.tail = FALSE)
AG_wind <- c(-Inf, qt(1 - alpha, df = n_wind - 1))

t_toets <- t.test(windsnelheid, mu = mu0, alternative = "greater", conf.level = 0.99)
cat("\nEenzijdige t-test met H0: mu = 11.7 en H1: mu > 11.7\n")
print(t_toets)
cat("Handmatig berekende testwaarde:", test_waarde_wind, "\n")
cat("Aanvaardingsgebied:", AG_wind, "\n")
cat("p-waarde:", p_waarde_wind, "\n")
if (p_waarde_wind < alpha) {
  cat("Besluit: H0 wordt verworpen op 1%. De gemiddelde windsnelheid is significant groter dan 11.7 km/h.\n")
} else {
  cat("Besluit: H0 wordt niet verworpen op 1%. Er is onvoldoende bewijs dat de gemiddelde windsnelheid groter is dan 11.7 km/h.\n")
}

png("figuren/wind_verkenning.png", width = 1100, height = 800)
par(mfrow = c(2, 2))
hist(windsnelheid, main = "Histogram windsnelheid", xlab = "Windsnelheid (km/h)")
boxplot(windsnelheid, horizontal = TRUE, main = "Boxplot windsnelheid", xlab = "Windsnelheid (km/h)")
qqnorm(windsnelheid, main = "QQ-plot windsnelheid")
qqline(windsnelheid)
plot(seq_along(windsnelheid), windsnelheid,
     xlab = "Observatie", ylab = "Windsnelheid (km/h)",
     main = "Ruwe windmetingen")
abline(h = mu0, lty = 2)
par(mfrow = c(1, 1))
dev.off()

sink()
