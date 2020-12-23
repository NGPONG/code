using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace Contract
{
    // 注意: 使用“重构”菜单上的“重命名”命令，可以同时更改代码和配置文件中的接口名“ICalculator”。
    [ServiceContract]
    public interface ICalculator
    {
        [OperationContract]
        string DoWork();
    }
}
