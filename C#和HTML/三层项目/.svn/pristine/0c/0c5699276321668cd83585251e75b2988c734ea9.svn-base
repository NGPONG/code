using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WP.Demo.Common;
using WP.Demo.DAL;
using WP.Demo.Model;

namespace WP.Demo.BLL
{
    public class HallInfoBLL
    {
        private HallInfoDAL objClient = new HallInfoDAL();

        /// <summary>
        ///  获取数据
        /// </summary>
        /// <returns>反序列化后的LIST集合</returns>
        public DataTable GetData()
        {
            try
            {
                List<byte[]> listSerializeBuff = this.objClient.GetData();
                List<HallInfoModel_GetData> listResult = SerializableObject.DeserializeObject<HallInfoModel_GetData>(listSerializeBuff);
                DataTable dtResult = ConvertWP.ToDataTable<HallInfoModel_GetData>(listResult);
                return dtResult;
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  检查是否存在相同的用户名
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public DataTable CheckHaveSameHallTitle(HallInfoModel model)
        {
            try
            {
                List<byte[]> listSerializeBuff = this.objClient.CheckHaveSameHallTitle(model);
                List<HallInfoModel_CheckHaveSameHallTitle> listResult = SerializableObject.DeserializeObject<HallInfoModel_CheckHaveSameHallTitle>(listSerializeBuff);
                DataTable dtResult = ConvertWP.ToDataTable<HallInfoModel_CheckHaveSameHallTitle>(listResult);
                return dtResult;
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  添加数据
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int AddHallInfoDetail(HallInfoModel model)
        {
            try
            {
                return this.objClient.AddHallInfoDetail(model);
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  修改数据
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int UpdateHallInfoDetail(HallInfoModel model)
        {
            try
            {
                return this.objClient.UpdateHallInfoDetail(model);
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  删除数据
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int DeleteHallInfoDetail(HallInfoModel model)
        {
            try
            {
                return this.objClient.DeleteHallInfoDetail(model);
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }

    }
}
