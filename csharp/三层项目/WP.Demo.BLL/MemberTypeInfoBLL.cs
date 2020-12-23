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
    public class MemberTypeInfoBLL
    {
        private MemberTypeInfoDAL objClient = new MemberTypeInfoDAL();

        /// <summary>
        ///  获取数据
        /// </summary>
        /// <returns>反序列化后的LIST集合</returns>
        public DataTable GetData()
        {
            try
            {
                List<byte[]> listSerializeBuff = this.objClient.GetData();
                List<MemberTypeInfoModel_GetData> listResult = SerializableObject.DeserializeObject<MemberTypeInfoModel_GetData>(listSerializeBuff);
                DataTable dtResult = ConvertWP.ToDataTable<MemberTypeInfoModel_GetData>(listResult);
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
        ///  检查是否存在相同的折扣
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public DataTable CheckHaveSameDiscountTitle(MemberTypeInfoModel model)
        {
            try
            {
                List<byte[]> listSerializeBuff = this.objClient.CheckHaveSameDiscountTitle(model);
                List<MemberTypeInfoModel_CheckHaveSameDiscountTitle> listResult = SerializableObject.DeserializeObject<MemberTypeInfoModel_CheckHaveSameDiscountTitle>(listSerializeBuff);
                DataTable dtResult = ConvertWP.ToDataTable<MemberTypeInfoModel_CheckHaveSameDiscountTitle>(listResult);
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
        public int AddMemberTypeInfoDetail(MemberTypeInfoModel model)
        {
            try
            {
                return this.objClient.AddMemberTypeInfoDetail(model);
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
        public int UpdateMemberTypeInfoDetail(MemberTypeInfoModel model)
        {
            try
            {
                return this.objClient.UpdateMemberTypeInfoDetail(model);
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
        public int DeleteMemberTypeInfoDetail(MemberTypeInfoModel model)
        {
            try
            {
                return this.objClient.DeleteMemberTypeInfoDetail(model);
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
