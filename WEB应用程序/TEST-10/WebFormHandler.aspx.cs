using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TEST_10
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            MyModule.objMyModuleEventStr.Add("HttpHandler【PageLoad】<br/>");
        }
        protected void Page_Init(object sender, EventArgs e)
        {
            MyModule.objMyModuleEventStr.Add("HttpHandler【PageInit】<br/>");
        }
        protected void Page_LoadViewState(object sender, EventArgs e)
        {
            MyModule.objMyModuleEventStr.Add("HttpHandler【PageLoadViewState】<br/>");
        }
        protected void Page_PostBackdata(object sender, EventArgs e)
        {
            MyModule.objMyModuleEventStr.Add("HttpHandler【PagePostBackdat】<br/>");
        }
        protected void Page_Validate(object sender, EventArgs e)
        {
            MyModule.objMyModuleEventStr.Add("HttpHandler【PageValidate】<br/>");
        }
        protected void Page_Event(object sender, EventArgs e)
        {
            MyModule.objMyModuleEventStr.Add("HttpHandler【PageEvent】<br/>");
        }

    }
}