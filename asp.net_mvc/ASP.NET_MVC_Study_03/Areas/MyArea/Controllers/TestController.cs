using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace ASP.NET_MVC_Study_03.Areas.MyArea.Controllers
{
    public class TestController : Controller
    {
        // GET: MyArea/Test
        public ActionResult Index()
        {
            return View();
        }
    }
}