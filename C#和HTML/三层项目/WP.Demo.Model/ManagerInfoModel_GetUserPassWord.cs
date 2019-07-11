using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WP.Demo.Model
{
    [Serializable]
    public partial class ManagerInfoModel_GetUserPassWord
    {
        public string MPwd { get; set; }
        public string MType { get; set; }
    }
}
