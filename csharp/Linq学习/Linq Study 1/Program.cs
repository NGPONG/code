﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Linq_Study_1
{
    #region Objects
    public class Customer
    {
        public int CustomerID { get; set; }
        public string Country { get; set; }
        public string Name { get; set; }
        public string City { get; set; }
        public List<Order> Orders { get; set; }
    }
    public class Order
    {
        public int OrderID { get; set; }
        public int CustomerID { get; set; }
        public int Total { get; set; }
        public DateTime OrderDate { get; set; }
        public List<Detail> Details { get; set; }
    }
    public class Detail
    {
        public int DetailID { get; set; }
        public int OrderID { get; set; }
        public double UnitPrice { get; set; }
        public double Quantity { get; set; }
        public int ProductID { get; set; }
    }
    public class Product
    {
        public int ProductID { get; set; }
        public string ProductName { get; set; }
    }
    #endregion
    class Program
    {
        #region Member
        public static List<Customer> customers = new List<Customer>();
        public static List<Order> orders = new List<Order>();
        public static List<Detail> details = new List<Detail>();
        public static List<Product> products = new List<Product>();
        #endregion
        static void Main(string[] args)
        {
            #region Init Sequence
            InitDetail();
            InitOrder();
            InitCustomer();
            InitProduct();
            #endregion


            #region start
            //var query_Exp = from c in customers
            //            select c.City;
            //var query_Fun = customers.Select(x => x.City); 
            #endregion

            #region 筛选在北京且名称以‘小’开头的顾客
            //var query_Exp = from c in customers
            //                where c.City == "北京" && c.Name.StartsWith("小")
            //                select c;

            //var query_Fun = customers.Where(c => c.City == "北京" && c.Name.StartsWith("小")); 
            #endregion

            #region 把集合中的CustomerID都+1 并且查询出来
            //var query_Exp = from c in customers
            //                let cTemp = c.CustomerID + 1
            //                where cTemp > 3
            //                select cTemp; 
            #endregion

            #region 把字符串集合中的句子都以空格分割出来，并都转换成小写打印出来
            //string[] strings =
            //{
            //"A penny saved is a penny earned.",
            //"The early bird catches the worm.",
            //"The pen is mightier than the sword."
            //};

            //var query = from sentenct in strings
            //            let words = sentenct.Split(' ')
            //            from word in words
            //            let wordProcess = word.ToLower()
            //            select wordProcess; 
            #endregion

            #region 为字符串中的每个字符进行排序
            //string str = "qwertyuiopasdfghjklzxcvbnm123456789";

            //var query_Exp = from s in str.ToCharArray()
            //                orderby s ascending
            //                let sProcess = s.ToString().ToUpper()
            //                select sProcess;

            //var query_Fun = str.ToCharArray().Select(x => x.ToString().ToUpper()).OrderBy(x => x);
            //var query_Fun2 = str.ToCharArray().Select(x => x.ToString().ToUpper()).OrderByDescending(x => x);
            #endregion

            #region 把字符串集合都按照每个元素的首字母进行分组，筛选出分组结果大于2的元素，并且每个筛选结果元素的末尾要加上 分组成功 的样式
            //string[] words = { "apples", "blueberries", "oranges", "bananas", "apricots" };

            //var query_Exp = from w in words
            //                group w by w[0] into g
            //                where g.Count() > 1
            //                select (from gProc in g
            //                        select gProc + $" 分组成功，这个是{g.Key.ToString()}组");

            //var query_Func = words.GroupBy(x => x[0])
            //                      .Where(g => g.Count() > 1)
            //                      .Select(x => x
            //                      .Select(y => y + $"分组成功，这个是{x.Key.ToString()}组"));
            #endregion

            #region 查询出顾客名称其所在的城市，还有这个顾客所下的订单的总金额还有这个订单所包含的商品
            //var query_Exp = from c in customers
            //                from o in c.Orders
            //                from d in o.Details
            //                join p in products on d.ProductID equals p.ProductID
            //                select new
            //                {
            //                    Name = c.Name,
            //                    City = c.City,
            //                    Money = d.Quantity * d.UnitPrice,
            //                    ProductName = p.ProductName
            //                };

            //var query_Fun = customers.SelectMany(c => c.Orders, (c, o) => new { Name = c.Name, City = c.City, Details = o.Details })
            //                      .SelectMany(oc => oc.Details, (oc, details) => new { Name = oc.Name, City = oc.City, Money = details.Quantity * details.UnitPrice, ProductID = details.ProductID })
            //                      .Join(products, ocd => ocd.ProductID, p => p.ProductID, (ocd, p) => new { Name = ocd.Name, City = ocd.City, Money = ocd.Money, ProductName = p.ProductName }); 
            #endregion

            // 标准的 join into 查询
            var query_Exp_Default = from p in products
                                    join d in details on p.ProductID equals d.ProductID into dGroup
                                    select dGroup;

            var query_Fun_Default = products.GroupJoin( details,
                                                        p => p.ProductID,
                                                        d => d.ProductID,
                                                        (p, dGroup) => dGroup);

            // 左连接形式的 join into 查询
            var query_Exp_left = from p in products
                                 join d in details on p.ProductID equals d.ProductID into dGroup
                                 select dGroup.DefaultIfEmpty();

            var query_Fun_left = products.GroupJoin(details,
                                                    p => p.ProductID,
                                                    d => d.ProductID,
                                                    (p, dGroup) => dGroup.DefaultIfEmpty());

            Console.ReadLine();
        }

        /// <summary>
        /// 初始化顾客信息
        /// </summary>
        static private void InitCustomer()
        {
            customers.Add(new Customer() { CustomerID = 0, City = "北京", Country = "中国", Name = "小米", Orders = orders.FindAll(c => c.CustomerID == 0) });
            customers.Add(new Customer() { CustomerID = 1, City = "首尔", Country = "韩国", Name = "三星", Orders = orders.FindAll(c => c.CustomerID == 1) });
            customers.Add(new Customer() { CustomerID = 2, City = "加州", Country = "美国", Name = "苹果", Orders = orders.FindAll(c => c.CustomerID == 2) });
            customers.Add(new Customer() { CustomerID = 3, City = "台北", Country = "中国", Name = "HTC", Orders = orders.FindAll(c => c.CustomerID == 3) });
            customers.Add(new Customer() { CustomerID = 4, City = "珠海", Country = "中国", Name = "魅族", Orders = orders.FindAll(c => c.CustomerID == 4) });
            customers.Add(new Customer() { CustomerID = 5, City = "北京", Country = "中国", Name = "华为", Orders = orders.FindAll(c => c.CustomerID == 5) });
            customers.Add(new Customer() { CustomerID = 6, City = "上海", Country = "中国", Name = "索尼", Orders = orders.FindAll(p => p.CustomerID == 6) });
            customers.Add(new Customer() { CustomerID = 7, City = "北京", Country = "中国", Name = "联想", Orders = orders.FindAll(c => c.CustomerID == 7) });
            customers.Add(new Customer() { CustomerID = 8, City = "上海", Country = "中国", Name = "诺基亚", Orders = orders.FindAll(c => c.CustomerID == 8) });
        }
        /// <summary>
        /// 初始化订单
        /// </summary>
        static private void InitOrder()
        {
            orders.Add(new Order() { OrderID = 0, CustomerID = 0, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 0) });
            orders.Add(new Order() { OrderID = 1, CustomerID = 0, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 1) });
            orders.Add(new Order() { OrderID = 2, CustomerID = 1, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 2) });
            orders.Add(new Order() { OrderID = 3, CustomerID = 1, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 3) });
            orders.Add(new Order() { OrderID = 4, CustomerID = 2, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 4) });
            orders.Add(new Order() { OrderID = 5, CustomerID = 2, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 5) });
            orders.Add(new Order() { OrderID = 6, CustomerID = 3, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 6) });
            orders.Add(new Order() { OrderID = 7, CustomerID = 3, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 7) });
            orders.Add(new Order() { OrderID = 8, CustomerID = 4, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 8) });
            orders.Add(new Order() { OrderID = 9, CustomerID = 5, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 9) });
            orders.Add(new Order() { OrderID = 10, CustomerID = 6, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 10) });
            orders.Add(new Order() { OrderID = 11, CustomerID = 6, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 11) });
            orders.Add(new Order() { OrderID = 12, CustomerID = 7, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 12) });
            orders.Add(new Order() { OrderID = 13, CustomerID = 7, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 13) });
            orders.Add(new Order() { OrderID = 14, CustomerID = 8, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 14) });
            orders.Add(new Order() { OrderID = 15, CustomerID = 8, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 15) });
            orders.Add(new Order() { OrderID = 16, CustomerID = 8, OrderDate = DateTime.Now, Details = details.FindAll(d => d.OrderID == 16) });
        }
        /// <summary>
        /// 初始化明细
        /// </summary>
        static private void InitDetail()
        {
            details.Add(new Detail() { DetailID = 0, OrderID = 0, ProductID = 0, Quantity = 1000, UnitPrice = 10 });
            details.Add(new Detail() { DetailID = 1, OrderID = 1, ProductID = 1, Quantity = 2134, UnitPrice = 8 });
            details.Add(new Detail() { DetailID = 2, OrderID = 2, ProductID = 1, Quantity = 1236, UnitPrice = 9 });
            details.Add(new Detail() { DetailID = 3, OrderID = 3, ProductID = 0, Quantity = 754, UnitPrice = 7 });
            details.Add(new Detail() { DetailID = 4, OrderID = 4, ProductID = 2, Quantity = 2354, UnitPrice = 12 });
            details.Add(new Detail() { DetailID = 5, OrderID = 5, ProductID = 0, Quantity = 6985, UnitPrice = 13 });
            details.Add(new Detail() { DetailID = 6, OrderID = 6, ProductID = 2, Quantity = 4213, UnitPrice = 10 });
            details.Add(new Detail() { DetailID = 7, OrderID = 7, ProductID = 3, Quantity = 1977, UnitPrice = 10 });
            details.Add(new Detail() { DetailID = 8, OrderID = 8, ProductID = 2, Quantity = 287, UnitPrice = 6 });
            details.Add(new Detail() { DetailID = 9, OrderID = 9, ProductID = 5, Quantity = 9778, UnitPrice = 12 });
            details.Add(new Detail() { DetailID = 10, OrderID = 10, ProductID = 4, Quantity = 854, UnitPrice = 11 });
            details.Add(new Detail() { DetailID = 11, OrderID = 11, ProductID = 2, Quantity = 756, UnitPrice = 10 });
            details.Add(new Detail() { DetailID = 12, OrderID = 12, ProductID = 3, Quantity = 1000, UnitPrice = 9 });
            details.Add(new Detail() { DetailID = 13, OrderID = 13, ProductID = 1, Quantity = 786, UnitPrice = 8 });
            details.Add(new Detail() { DetailID = 14, OrderID = 14, ProductID = 3, Quantity = 346, UnitPrice = 7 });
            details.Add(new Detail() { DetailID = 15, OrderID = 15, ProductID = 2, Quantity = 576, UnitPrice = 6 });
            details.Add(new Detail() { DetailID = 16, OrderID = 16, ProductID = 0, Quantity = 782, UnitPrice = 10 });
        }
        /// <summary>
        /// 初始化产品
        /// </summary>
        static private void InitProduct()
        {
            products.Add(new Product() { ProductID = 0, ProductName = "samsung" });
            products.Add(new Product() { ProductID = 1, ProductName = "nokia" });
            products.Add(new Product() { ProductID = 2, ProductName = "apple" });
            products.Add(new Product() { ProductID = 3, ProductName = "xiaomi" });
            products.Add(new Product() { ProductID = 4, ProductName = "huawei" });
            products.Add(new Product() { ProductID = 123, ProductName = "lenovo" });
        }
    }
}
