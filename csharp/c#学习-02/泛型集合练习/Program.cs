using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 泛型集合练习
{
    class Program
    {
        static void Main(string[] args)
        {
            //string[] strs1 = { "a", "b", "c", "d", "e" };
            //string[] strs2 = { "d", "e", "f", "g", "h" };
            //List<string> list1 = new List<string>();
            //list1.AddRange(strs1);
            //List<string> list2 = new List<string>();
            //list2.AddRange(strs2);
            //list2.Remove("d");
            //list2.Remove("e");
            //list1.AddRange(list2);
            //for (int i = 0; i < list1.Count; i++)
            //{
            //    Console.WriteLine(list1[i]);
            //}
            //Console.ReadLine();

            //2
            //List<int> list = new List<int>();
            //Random r = new Random();
            //Console.WriteLine("请输入需要循环的次数");
            //int need = Convert.ToInt32(Console.ReadLine());
            //for (int i = 0; i < need; i++)
            //{
            //    int n = r.Next(1, 101);

            //    if (i == 0 && n % 2 != 0)
            //    {
            //        while (true)
            //        {
            //            n = r.Next(1, 101);
            //            if (n % 2 == 0)
            //            {
            //                list.Add(n);
            //                break;
            //            }
            //        }
            //    }
            //    else 
            //    if (list.Contains(n) && (n % 2 != 0))
            //    {
            //        while (true)
            //        {
            //            n = r.Next(1, 101);
            //            if ((list.Contains(n) == false) && (n % 2 == 0))
            //            {
            //                list.Add(n);
            //                break;
            //            }
            //        }
            //    }
            //    else
            //    {
            //        while (true)
            //        {
            //            n = r.Next(1, 101);
            //            if ((list.Contains(n) == false) && (n % 2 == 0))
            //            {
            //                list.Add(n);
            //                break;
            //            }
            //        }
            //    }
            //}
            //list.Sort();
            //for (int i = 0; i < list.Count; i++)
            //{
            //    Console.WriteLine(list[i]);
            //}
            //Console.ReadLine();

            //List<int> list = new List<int>();
            //Random r = new Random();

            //for (int i = 0; i < 50; i++)
            //{
            //    int n = r.Next(1, 101);
            //    if (list.Contains(n) == false && n % 2 == 0)
            //    {
            //        list.Add(n);
            //    }
            //    else 
            //    {
            //        while (true)
            //        {
            //            n = r.Next(1, 101);
            //            if (list.Contains(n) == false && n % 2 == 0)
            //            {
            //                list.Add(n);
            //                break;
            //            }
            //        }
            //    }
            //}
            //list.Sort();
            //for (int j = 0; j < list.Count; j++)
            //{
            //    Console.WriteLine(list[j]);
            //}
            //Console.ReadLine();

            //List<int> list = new List<int>();
            // Random r = new Random();
            //for (int i = 0; i < 50; i++)
            // {
            //    int n = r.Next(1, 101);
            //    if (list.Contains(n) || n % 2 != 0)
            //    {
            //        while (true)
            //        {
            //            n = r.Next(1, 101);
            //            if (list.Contains(n) == false && n % 2 == 0)
            //            {
            //                list.Add(n);
            //                break;
            //            }
            //        }
            //    }
            //    else
            //    {
            //        list.Add(n);
            //    }
            //}
            //list.Sort();
            //for (int j = 0; j < list.Count; j++)
            //{
            //    Console.WriteLine(list[j]);
            //}
            //Console.ReadLine();


            //3
            int[] nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
            List<int> listou = new List<int>();
            List<int> listji = new List<int>();

            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] % 2 == 0)
                {
                    listou.Add(nums[i]);
                }
                else 
                {
                    listji.Add(nums[i]);
                }
            }
            foreach (var item in listou)
            {
                Console.WriteLine(item);
            }
            foreach (var item in listji)
            {
                Console.WriteLine(item);
            }
            Console.ReadLine();
        }
    }
}
