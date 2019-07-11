using Contract;
using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Client
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                using (ChannelFactory<ICalculator> channelFactory = new ChannelFactory<ICalculator>(new BasicHttpBinding(), @"http://192.168.1.104:8731/Design_Time_Addresses/Implement/Calculator/"))
                {
                    ICalculator proxy = channelFactory.CreateChannel();
                    using (proxy as IDisposable)
                    {
                        while (true)
                        {
                            Console.WriteLine(proxy.DoWork());
                            Thread.Sleep(100);
                        }
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                Console.WriteLine(e.InnerException.Message);
                Console.ReadLine();
            }


        }
    }
}
