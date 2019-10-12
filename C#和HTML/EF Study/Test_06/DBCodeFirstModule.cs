namespace Test_06
{
    using System;
    using System.Data.Entity;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;

    public partial class DBCodeFirstModule : DbContext
    {
        public DBCodeFirstModule()
            : base("name=DBCodeFirstModule2")
        {
        }

        public virtual DbSet<ClassInfo> ClassInfo { get; set; }
        public virtual DbSet<Student> Student { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Entity<ClassInfo>()
                .HasMany(e => e.Student)
                .WithRequired(e => e.ClassInfo)
                .WillCascadeOnDelete(false);
        }
    }
}
