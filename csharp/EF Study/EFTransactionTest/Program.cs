using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Transactions;

namespace EFTransactionTest
{
    class Program
    {
        static void Main(string[] args)
        {
            #region SavaChanges() Default Transation Feature
            //using (EFDemo2Entities db = new EFDemo2Entities())
            //{
            //    // 该事务管理SavaChanges()前所有的修改

            //    Order order = new Order()
            //    {
            //        OrderName = "NGPONG Test",
            //        CreateDate = DateTime.Now
            //    };
            //    db.Order.Add(order);

            //    Product product = new Product()
            //    {
            //        ProductName = "NGPONG TrantestPro",
            //        OrderId = 100 // 模拟错误，OrderId为外键，输入一个不存在的OrderId
            //    };
            //    db.Product.Add(product);

            //    db.SaveChanges();
            //}
            #endregion

            #region DbContextTransaction to freely manage transactions manually
            //using (EFDemo2Entities db = new EFDemo2Entities())
            //{
            //    // Begin Trans
            //    using (var dbTrans = db.Database.BeginTransaction())
            //    {
            //        // 该实现方式可以手动管理事务，对比单纯的SaveChanges()灵活，并且能够管理在一个上下文档中多次SavaeChanges()的回滚
            //        try
            //        {
            //            // 前两次通过SaveChanges()是已经成功执行的，但是第三次通过SQL语句进行插入数据的时候失败了，所以前两次的成功执行也一起回滚了
            //            Order order = new Order()
            //            {
            //                OrderName = "NGPONG Test",
            //                CreateDate = DateTime.Now
            //            };
            //            db.Order.Add(order);
            //            db.SaveChanges();

            //            Product product = new Product()
            //            {
            //                ProductName = "NGPONG Test Pro",
            //                Order = order
            //            };
            //            db.Product.Add(product);
            //            db.SaveChanges();

            //            // 故意制造失败的情况，OrderId字段有着非空约束
            //            db.Database.ExecuteSqlCommand(
            //                "insert into Product (ProductName) values(@ProductName)",
            //                new SqlParameter[] { new SqlParameter("@ProductName", "NGPONG ProductTest") });

            //            // Commit Trans
            //            dbTrans.Commit();
            //        }
            //        catch (Exception objException)
            //        {
            //            // Rollback Trans
            //            dbTrans.Rollback();
            //        }
            //    }
            //}
            #endregion

            #region TransactionScope to freely manage transactions manually it's similar to the DbContextTransaction feature
            //using (EFDemo2Entities db = new EFDemo2Entities())
            //{
            //    // Begin Trans
            //    using (TransactionScope dbTrans = new TransactionScope())
            //    {
            //        try
            //        {
            //            // 前两次通过SaveChanges()是已经成功执行的，但是第三次通过SQL语句进行插入数据的时候失败了，所以前两次的成功执行也一起回滚了
            //            Order order = new Order()
            //            {
            //                OrderName = "NGPONG Test",
            //                CreateDate = DateTime.Now
            //            };
            //            db.Order.Add(order);
            //            db.SaveChanges();

            //            Product product = new Product()
            //            {
            //                ProductName = "NGPONG Test Pro",
            //                Order = order
            //            };
            //            db.Product.Add(product);
            //            db.SaveChanges();

            //            // 故意制造失败的情况，OrderId字段有着非空约束
            //            db.Database.ExecuteSqlCommand(
            //                "insert into Product (ProductName) values(@ProductName)",
            //                new SqlParameter[] { new SqlParameter("@ProductName", "NGPONG ProductTest") });

            //            // Commit Trans
            //            dbTrans.Complete();
            //        }
            //        catch (Exception objException)
            //        {
            //            // Rollback Trans
            //            Transaction.Current.Rollback();
            //        }
            //    }
            //} 
            #endregion
        }
    }
}
