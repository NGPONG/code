using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace NGPONG.BookShop.WebApplication.test
{
    public partial class test_03 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            //[{"bookid":"1","Msg":"hahah"},{"bookid":"2","Msg":"NGPONG"}]
            this.Repeater1.DataSource = JsonConvert.DeserializeObject<JArray>("[{\"bookid\":\"1\",\"Msg\":\"hahah\"},{\"bookid\":\"2\",\"Msg\":\"NGPONG\"}]");
            this.Repeater1.DataBind();
        }
    }
}