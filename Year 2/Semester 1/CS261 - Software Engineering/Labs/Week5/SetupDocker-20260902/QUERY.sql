USE master;
GO
 
IF NOT EXISTS (SELECT name FROM sys.databases WHERE name = 'POS')
BEGIN
    CREATE DATABASE POS;
END
GO
 
USE POS;
GO

SELECT * FROM dbo.Product