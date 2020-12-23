using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WP.Demo.Model
{
    [Serializable]
    public class TableInfoModel_GetData
    {
        public string TId { get; set; }
        public string TTitle { get; set; }
        public string THallName { get; set; }
        public string TIsFree { get; set; }
    }
}
