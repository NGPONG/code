namespace Test_07
{
    using System;
    using System.Data.Entity;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;

    public partial class Model1 : DbContext
    {
        public Model1()
            : base("name=Model1")
        {
        }

        public virtual DbSet<CustomerSet> CustomerSet { get; set; }
        public virtual DbSet<Order> Order { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Entity<CustomerSet>()
                .HasMany(e => e.Order)
                .WithRequired(e => e.CustomerSet)
                .WillCascadeOnDelete(false);
        }
    }
}
