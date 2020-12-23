using Implement;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace Servers
{
    class Program
    {
        static void Main(string[] args)
        {
            ConfigurationManager.GetSection("system.serviceModel/")

            using (ServiceHost host = new ServiceHost(typeof(Calculator))) 
            {
                host.Opened += host_Opened;
                host.Open();

                Console.ReadLine();
            }
        }
        /// <summary>
        ///  服务启动事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        static void host_Opened(object sender, EventArgs e)
        {
            try
            {
                Console.WriteLine("服务已经启动！请按任意键关闭！");
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null) 
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
    }
}
