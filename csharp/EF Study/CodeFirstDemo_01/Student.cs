using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeFirstDemo_01
{
    public class Student
    {
        [Key]
        public int StudentId { get; set; }
        [StringLength(64)]
        [Required]
        public string StudentName { get; set; }
        [Required]
        public int StudentAge { get; set; }
        public virtual Class Class { get; set; }    
    }
}
