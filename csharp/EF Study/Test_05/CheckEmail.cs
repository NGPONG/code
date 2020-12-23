namespace Test_05
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("CheckEmail")]
    public partial class CheckEmail
    {
        public int Id { get; set; }

        public bool? Actived { get; set; }

        [StringLength(50)]
        public string ActiveCode { get; set; }
    }
}
