#include <iostream>
#include <random>

double monteCarloPi(int n)
{
  int inside = 0;
  for (int i = 0; i < n; i++)
  {
    // Create a random engine (seeded with random device)
    std::random_device rd;
    std::mt19937 gen(rd());

    // Uniform real distribution between -1 and 1
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    // Get a random number
    double x = dist(gen);
    double y = dist(gen);

    if (x*x + y*y <= 1)
      inside++;
  }

  return 4 * (double)inside / n;
}

int main()
{
  int n;
  std::cin >> n;

  std::cout << "The approximated number is: " << monteCarloPi(n) << std::endl;
}
