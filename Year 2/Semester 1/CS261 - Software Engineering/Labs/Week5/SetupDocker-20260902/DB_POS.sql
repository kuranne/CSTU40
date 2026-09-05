
-- Run against MS SQL Server (SA account), Docker container on localhost:1433
USE master;
GO
 
IF NOT EXISTS (SELECT name FROM sys.databases WHERE name = 'POS')
BEGIN
    CREATE DATABASE POS;
END
GO
 
USE POS;
GO
 
IF OBJECT_ID('dbo.Product', 'U') IS NOT NULL
    DROP TABLE dbo.Product;
GO
 
CREATE TABLE dbo.Product (
    id          INT IDENTITY(1,1) PRIMARY KEY,
    name        NVARCHAR(100)   NOT NULL,
    description NVARCHAR(255)   NULL,
    price       DECIMAL(10,2)   NOT NULL
);
GO
 
INSERT INTO dbo.Product (name, description, price) VALUES
('Wireless Mouse',        'Ergonomic 2.4GHz wireless mouse',        19.99),
('Mechanical Keyboard',   'RGB backlit mechanical keyboard',        59.99),
('USB-C Hub',             '7-in-1 USB-C hub with HDMI',             29.50),
('Laptop Stand',          'Adjustable aluminum laptop stand',       25.00),
('Webcam 1080p',          'Full HD webcam with built-in mic',       34.99),
('Noise Cancelling Headphones', 'Over-ear Bluetooth headphones',    89.99),
('Portable SSD 1TB',      'USB 3.2 external SSD, 1TB',              109.99),
('Desk Lamp LED',         'Dimmable LED desk lamp with USB port',   22.50),
('Bluetooth Speaker',     'Compact portable Bluetooth speaker',     39.99),
('Monitor 27-inch',       '27" IPS monitor, 1440p, 75Hz',           259.00);
GO
 


INSERT INTO dbo.Product (name, description, price) VALUES
('Coffee Beans', 'Premium roasted coffee beans', 250.00),
('Espresso Machine', 'Compact espresso maker for home use', 4200.00),
('Milk Frother', 'Electric milk frother for latte art', 890.00),
('Tea Leaves', 'Organic green tea leaves', 180.00),
('Ceramic Mug', 'Classic ceramic coffee mug', 320.00),
('Coffee Grinder', 'Conical burr coffee grinder', 3200.00),
('Sugar Syrup', 'Vanilla flavored sugar syrup', 150.00),
('French Press', 'Stainless steel French press', 1200.00),
('Cold Brew Jar', 'Glass jar for cold brew coffee', 650.00),
('Disposable Cup', '12 oz paper coffee cup', 95.00);
GO