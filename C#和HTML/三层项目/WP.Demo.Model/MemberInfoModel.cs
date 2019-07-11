using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WP.Demo.Model
{
    public class MemberInfoModel
    {
        public int MId { get; set; }
        public int MTypeId { get; set; }
        public string MName { get; set; }
        public string MPhone { get; set; }
        public string MMoney { get; set; }
        public bool MIsDelete { get; set; }
    }
}
