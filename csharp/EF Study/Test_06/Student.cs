namespace Test_06
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("Student")]
    public partial class Student
    {
        public int StudentId { get; set; }

        [StringLength(64)]
        public string StudentName { get; set; }

        public int? StudentAge { get; set; }

        public int ClassInfoId { get; set; }

        public virtual ClassInfo ClassInfo { get; set; }
    }
}
