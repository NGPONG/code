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
    public class DishInfoBLL
    {
        private DishInfoDAL objClient = new DishInfoDAL();

        /// <summary>
        ///  获取数据
        /// </summary>
        /// <returns>反序列化后的LIST集合</returns>
        public DataTable GetData()
        {
            try
            {
                List<byte[]> listSerializeBuff = this.objClient.GetData();
                List<DishInfoModel_GetData> listResult = SerializableObject.DeserializeObject<DishInfoModel_GetData>(listSerializeBuff);
                DataTable dtResult = ConvertWP.ToDataTable<DishInfoModel_GetData>(listResult);
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
        ///  检查是否存在相同的菜品
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public DataTable CheckHaveSameDishTitle(DishInfoModel model)
        {
            try
            {
                List<byte[]> listSerializeBuff = this.objClient.CheckHaveSameDishTitle(model);
                List<DishInfoModel_CheckHaveSameDishTitle> listResult = SerializableObject.DeserializeObject<DishInfoModel_CheckHaveSameDishTitle>(listSerializeBuff);
                DataTable dtResult = ConvertWP.ToDataTable<DishInfoModel_CheckHaveSameDishTitle>(listResult);
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
        public int AddDishInfoDetail(DishInfoModel model)
        {
            try
            {
                return this.objClient.AddDishInfoDetail(model);
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
        public int UpdateDishInfoDetail(DishInfoModel model)
        {
            try
            {
                return this.objClient.UpdateDishInfoDetail(model);
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
        public int DeleteDishInfoDetail(DishInfoModel model)
        {
            try
            {
                return this.objClient.DeleteDishInfoDetail(model);
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
