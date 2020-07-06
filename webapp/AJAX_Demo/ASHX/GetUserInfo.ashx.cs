using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Script.Serialization;
using WP._3_TierArchitecture.Common;

namespace AJAX_Demo.ASHX
{
    /// <summary>
    /// GetUserInfo 的摘要说明
    /// </summary>
    public class GetUserInfo : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            // 获取UserInfo数据
            DataTable dtResult = SqlHelper.GetDataTable("select * from userinfo order by userid desc", null);

            // 加入模型集合
            List<Module.UserInfo> userInfos = new List<Module.UserInfo>();
            foreach (DataRow drItem in dtResult.Rows)
            {
                userInfos.Add(new Module.UserInfo() { UserId = Convert.ToInt32(drItem["UserId"]), UserName = Convert.ToString(drItem["UserName"]), UserAge = Convert.ToInt32(drItem["UserAge"]), UserAddress = Convert.ToString(drItem["UserAddress"]), UserWork = Convert.ToString(drItem["UserWork"]) });
            }

            // 序列化JSON数据
            JavaScriptSerializer serializer = new JavaScriptSerializer();
            string jsonStr = serializer.Serialize(userInfos);

            context.Response.Write(jsonStr);
        }

        public bool IsReusable
        {
            get
            {
                return false;
            }
        }
    }
}