Author: Kasper Engelen

# Loading this database in Datagrip

In this readme you will learn how to load this database in Datagrip

## Requirements

Make sure that Datagrip and postgresql are installed. Also, make sure you downloaded and extracted the archive with the database files.

## Connecting datagrip to postgres

Datagrip is a general piece of software that can be used to manipulate data inside SQL databases. We will now connect Datagrip to the postgres database engine.

- Open datagrip
- On the left, you can see "Database Explorer"
- Click the "+" sign
- Click on "Data source -> Postgresql"
- The default settings should be OK (localhost, "postgres" db, etc.)
- If needed, click "download missing driver files" on the buttom.
- Click "test connection"
- Click OK

Datagrip should now be connected to postgres.

## Importing the database files

On the right, you can see "Files".

- Right mouse button -> "Attach directory to project"
- Select the directory with the `.sql` files that you downloaded.

## Creating the tables

Now, it is time to create the tables. The files you can see under "Files" on the right will be used to do this.

- "schema-employees.sql" -> right mouse button -> Run
	* You will now see a small window.
	* Make sure to add a target. Select "postgres" as the target.
	* Click "run"
- Verify on the left hand side that all tables were created under "postgres -> public -> tables". The tables should be empty.

## Filling the tables

Finally, we need to fill the tables with data.

- On the right, select all `.sql` files 1 to 8.
- Right mouse button -> run
	* You will once again see a small window.
	* Make sure to add a target. Select "postgres" as the target.
	* Click "run"
- This will take a while.

You are now ready to use the data in the database!

## Performing queries

- At the top of the window, open the "File" menu
- Select "New -> Query console"
- You will now see an interactive command line interface that can be used to do `SELECT` queries.
- Run `SELECT * FROM departments;`
- At the bottom of the window, under "Output" you will see the results.
