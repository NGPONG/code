using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Activation;
using System.Runtime.Remoting.Messaging;
using System.Runtime.Remoting.Proxies;
using System.Text;
using System.Threading.Tasks;

namespace AOP_TEST
{
    class Program
    {
        static void Main(string[] args)
        {
            ORMClass @class = new ORMClass();
            @class.DoSomething();
        }
    }

    [Aop]
    public class ORMClass
    {
        public void DoSomething()
        {
            Console.WriteLine("123");
        }
    }

    class AopAttribute : ProxyAttribute
    {
        public override MarshalByRefObject CreateInstance(Type serverType)
        {
            AopProxy realProxy = new AopProxy(serverType);
            return realProxy.GetTransparentProxy() as MarshalByRefObject;
        }
    }

    class AopProxy : RealProxy
    {
        public AopProxy(Type serverType)
            : base(serverType)
        {

        }

        public override IMessage Invoke(IMessage msg)
        {
            if (msg is IConstructionCallMessage) // 如果是构造函数
            {
                IConstructionCallMessage constructCallMsg = msg as IConstructionCallMessage;
                IConstructionReturnMessage constructionReturnMessage = this.InitializeServerObject((IConstructionCallMessage)msg);
                RealProxy.SetStubData(this, constructionReturnMessage.ReturnValue);
                return constructionReturnMessage;
            }
            else if (msg is IMethodCallMessage) //如果是方法调用（属性也是方法调用的一种）
            {
                IMethodCallMessage callMsg = msg as IMethodCallMessage;
                object[] args = callMsg.Args;
                IMessage message;
                try
                {
                    if (callMsg.MethodName.StartsWith("set_") && args.Length == 1)
                    {

                        //这里检测到是set方法，然后应试怎么调用对象的其它方法呢？

                    }
                    object o = callMsg.MethodBase.Invoke(GetUnwrappedServer(), args);
                    message = new ReturnMessage(o, args, args.Length, callMsg.LogicalCallContext, callMsg);
                }
                catch (Exception e)
                {
                    message = new ReturnMessage(e, callMsg);
                }

                return message;
            }
            return msg;
        }
    }
}
