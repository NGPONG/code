namespace CodeFirstDemo_02
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity;
    using System.Data.Entity.ModelConfiguration.Conventions;
    using System.Linq;

    public class MyTestModule : DbContext
    {
        //您的上下文已配置为从您的应用程序的配置文件(App.config 或 Web.config)
        //使用“MyTestModule”连接字符串。默认情况下，此连接字符串针对您的 LocalDb 实例上的
        //“CodeFirstDemo_02.MyTestModule”数据库。
        // 
        //如果您想要针对其他数据库和/或数据库提供程序，请在应用程序配置文件中修改“MyTestModule”
        //连接字符串。
        public MyTestModule()
            : base("name=MyTestModule")
        {

        }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            // 创建表的时候，表的后缀名不添加负数形式
            modelBuilder.Conventions.Remove<PluralizingTableNameConvention>();
        }

        //为您要在模型中包含的每种实体类型都添加 DbSet。有关配置和使用 Code First  模型
        //的详细信息，请参阅 http://go.microsoft.com/fwlink/?LinkId=390109。
        public virtual DbSet<Order> Order { get; set; }
        public virtual DbSet<Product> Product { get; set; }
    }
    
    public class Order
    {
        [Key]
        public int OrderId { get; set; }
        [StringLength(64)]
        public string OrderName { get; set; }
        public DateTime CreateDate { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<Product> Products { get; set; }
    }

    public class Product
    {
        [Key]
        public int ProductId { get; set; }
        [StringLength(64)]
        public string ProductName { get; set; }
        public int OrderId { get; set; }
        [ForeignKey("OrderId")]
        public Order Order { get; set; }
    }
}