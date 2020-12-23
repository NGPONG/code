namespace Test_07
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("Person")]
    public partial class Person
    {
        public int Id { get; set; }

        [StringLength(128)]
        public string Name { get; set; }

        public int? Age { get; set; }

        [StringLength(512)]
        public string Address { get; set; }
    }
}
