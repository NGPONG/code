using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ProOperation;
using System.IO;
using System.Reflection;

namespace ProFactory
{
    public class Factory
    {
        public static Operation GetOper(string type, int numberone, int numbertwo) 
        {
            Operation oper = null;
            string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Plug");
            //拿到Plug目录下的所有dll文件
            string[] DllFiles = Directory.GetFiles(path, "*.dll");

            foreach (string item1 in DllFiles)
            {
                //加载Plug目录下的每一个dll文件
                Assembly ass = Assembly.LoadFile(item1);
                //获得每一个dll文件下的类
                Type[] typs = ass.GetExportedTypes();

                for (int i = 0; i < typs.Length; i++)
                {
                    //判断当前类为Operation的子类，并且该类不是抽象类
                    if (typs[i].IsSubclassOf(typeof(Operation)) && !typs[i].IsAbstract) 
                    {
                        oper = (Operation)Activator.CreateInstance(typs[i], numberone, numbertwo);

                        if (oper.Type == type)
                        {
                            return oper;
                        }
                        else 
                        {
                            oper = null;
                        }

                    }
                }
            }
            return oper;
        }
    }
}
