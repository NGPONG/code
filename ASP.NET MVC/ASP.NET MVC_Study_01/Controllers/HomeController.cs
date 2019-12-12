using ASP.NET_MVC_Study_01.Models;
using Newtonsoft.Json;
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
            return View(new MyModels() { Age = 11, Name = "wupeng" });
        }

        [HttpGet]
        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";
            return View();
        }

        public void Test()
        {
            try
            {
                TestExp();
            }
            catch (Exception e)
            {

                throw;
            }
        }

        public void TestExp()
        {
            throw new Exception("哈哈哈");
        }

        [HttpPost]
        public ActionResult TestAPI()
        {
            return Content(JsonConvert.SerializeObject(new UserInfo() { UserName = "吴鹏", Email = "pengpeng1997428@gmail.com", ID = 1, RegTime = DateTime.Now, UserPass = "Pengqi1997.0428" }), "application/json");
        }

        [HttpPost]
        public ActionResult TestAP3 ()
        {
            return Json(new UserInfo() { UserName = "吴鹏", Email = "pengpeng1997428@gmail.com", ID = 1, RegTime = DateTime.Now, UserPass = "Pengqi1997.0428" });
        }

        [HttpGet]
        public ActionResult TestAPI2(UserInfo users)
        {
            return base.View();
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