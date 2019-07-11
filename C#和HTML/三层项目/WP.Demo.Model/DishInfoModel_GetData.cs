using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WP.Demo.Model
{
    [Serializable]
    public class DishInfoModel_GetData
    {
        public string DId { get; set; }
        public string DTitle { get; set; }
        public string DTypeTitle { get; set; }
        public string DPrice { get; set; }
        public string DChar { get; set; }
    }
}
