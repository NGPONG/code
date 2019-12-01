using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
using System.Data;
using System.Linq;
using System.Reflection;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Test_08
{
    class Program
    {
        List<string> strTags = new List<string>();

        static void Main(string[] args)
        {
            TypeDescriptor.AddProvider(new AssociatedMetadataTypeTypeDescriptionProvider(typeof(Class), typeof(ClassMetadata)),typeof(Class));
            var art = typeof(Class).GetProperty("Name").GetCustomAttributes(true);
        }
    }

    public class Class
    {
        public string Name { get; set; }
    }
    public class ClassMetadata
    {
        [Required]
        public string Name { get; set; }
    }
}
        