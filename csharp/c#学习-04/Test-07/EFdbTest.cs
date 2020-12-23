namespace Test_07
{
    using System;
    using System.Data.Entity;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;

    public partial class EFdbTest : DbContext
    {
        public EFdbTest()
            : base("name=EFdbTest")
        {
        }

        public virtual DbSet<Person> Person { get; set; }
        public virtual DbSet<Phone> Phone { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Phone>()
                .Property(e => e.PhoneNumber)
                .HasPrecision(18, 0);
        }
    }
}
