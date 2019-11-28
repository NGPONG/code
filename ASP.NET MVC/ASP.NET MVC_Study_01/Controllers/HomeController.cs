using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace ASP.NET_MVC_Study_01.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index(string id)
        {
            return View();
        }

        [HttpGet]
        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";
            var views = base.View();
            return View();
        }

        [HttpGet]
        public void TestAPI2()
        {
            var hello = ViewBag.Hello;
            int age = ViewBag.Age;
            HttpContext.Response.Write("Hello,World!");
        }

        [HttpGet]
        public void TestAPI(UserInfo users)
        {
            base.ViewBag.Hello = "World";
            base.ViewBag.Age = 22;
            HttpContext.Response.Redirect("/Home/TestAPI2");
        }

        [HttpGet]
        public ActionResult TestAction()
        {
            return base.View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
    }

    public class UserInfo
    {
        public int ID { get; set; }
        public string UserName { get; set; }
        public string UserPass { get; set; }
        public System.DateTime RegTime { get; set; }
        public string Email { get; set; }
    }

    public class RemoteInfo
    {
        public string MyMessage { get; set; }

    }
}