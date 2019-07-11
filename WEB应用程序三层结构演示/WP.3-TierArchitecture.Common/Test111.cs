using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WP._3_TierArchitecture.Common
{
    public static class Test111
    {
        public static string MyName = ConfigurationManager.AppSettings["hello"];
    }
}
