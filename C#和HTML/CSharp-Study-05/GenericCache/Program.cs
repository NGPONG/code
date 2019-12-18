using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenericCache
{
    class Program
    {
        static void Main(string[] args)
        {
            GenericCacheTest<object>.TestGenericStorage();
            DictionaryCacheTest.TestDictionaryStorage();

            Console.ReadKey(true);
        }
    }

    public static class Cache_Generic<T>
    {
        public static object Instance { get; set; }
    }

    public static class Cache_Dic
    {
        public static Dictionary<Type, object> Instance { get; set; }
    }

    public class GenericCacheTest<T>
    {
        static GenericCacheTest()
        {
            Cache_Generic<T>.Instance = new object();
        }

        public static void TestGenericStorage()
        {
            Stopwatch watch = new Stopwatch();
            watch.Start();

            for (int i = 0; i < 100_000_000; i++)
            {
                var obj = Cache_Generic<T>.Instance;
            }

            watch.Stop();
            Console.WriteLine($"GenericCache:{watch.ElapsedMilliseconds.ToString()}");
        }
    }

    public class DictionaryCacheTest
    {
        static DictionaryCacheTest()
        {
            Cache_Dic.Instance = new Dictionary<Type, object>();

            Cache_Dic.Instance[typeof(object)] = new object();
        }

        public static void TestDictionaryStorage()
        {
            var type = typeof(object);

            Stopwatch watch = new Stopwatch();
            watch.Start();

            for (int i = 0; i < 100_000_000; i++)
            {
                var obj = Cache_Dic.Instance[type];
            }

            watch.Stop();
            Console.WriteLine($"DictionaryCache:{watch.ElapsedMilliseconds.ToString()}");
        }
    }
}