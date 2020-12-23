namespace Test_07
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("Phone")]
    public partial class Phone
    {
        public int Id { get; set; }

        [StringLength(128)]
        public string PhoneType { get; set; }

        public decimal? PhoneNumber { get; set; }
    }
}
