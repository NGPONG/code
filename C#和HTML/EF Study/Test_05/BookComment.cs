namespace Test_05
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("BookComment")]
    public partial class BookComment
    {
        public int Id { get; set; }

        [Required]
        public string Msg { get; set; }

        public DateTime CreateDateTime { get; set; }

        public int BookId { get; set; }
    }
}
