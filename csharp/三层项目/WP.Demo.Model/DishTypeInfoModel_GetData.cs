using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WP.Demo.Model
{
    [Serializable]
    public partial class DishTypeInfoModel_GetData
    {
        public string DId { get; set; }
        public string DTitle { get; set; }
    }
}
