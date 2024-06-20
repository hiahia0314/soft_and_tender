import requests
import json

API_KEY='GFqZ1MCrjy5lcWhSPlAhxwpA'
SECRET_KEY='gfTVxfhSoGm0wcWKn3sMvVZqp5FfAMGk'

def main():
    # API接口的url
    url = "https://aip.baidubce.com/rpc/2.0/ernievilg/v1/getImgv2?access_token=" + get_access_token()
    # 发送请求获取网页内容
    payload = json.dumps({
        "task_id": "1777279184584773972"
    })
    headers = {
        'Content-Type': 'application/json',
        'Accept': 'application/json'
    }
    response = requests.request("POST", url, headers=headers, data=payload)
    print('请求的返回值：', response.text)
# 获取Access Token
def get_access_token():
    """
    使用 AK，SK 生成鉴权签名（Access Token）
    :return: access_token，或是None(如果错误)
    """
    url = "https://aip.baidubce.com/oauth/2.0/token"
    params = {"grant_type": "client_credentials", "client_id": API_KEY, "client_secret": SECRET_KEY}
    return str(requests.post(url, params=params).json().get("access_token"))


if __name__ == '__main__':
    main()

