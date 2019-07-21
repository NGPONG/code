using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test_03
{
    class Program
    {
        static void Main(string[] args)
        {
            var lst = new List<Stat>
            {
                new Stat{Id=1,Name="N1",Value=5},
                new Stat{Id=2,Name="N2",Value=2},
                new Stat{Id=3,Name="N3",Value=6},
                new Stat{Id=4,Name="N2",Value=15},
                new Stat{Id=5,Name="N1",Value=20},
                new Stat{Id=6,Name="N6",Value=3},
                new Stat{Id=7,Name="N5",Value=8},
            };

            var g = lst.GroupBy(x => x.Name);
            List<List<Stat>> stats = new List<List<Stat>>();
            foreach (var item in g)
            {
                stats.Add(item.ToList<Stat>());
            }
            Console.ReadKey();
        }
    }
    public class Stat
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Value { get; set; }
    }
}
