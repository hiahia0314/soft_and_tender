import requests
import json
ID='60374232'
API_KEY='GFqZ1MCrjy5lcWhSPlAhxwpA'
SECRET_KEY='gfTVxfhSoGm0wcWKn3sMvVZqp5FfAMGk'
def main1():
    url = "https://aip.baidubce.com/rpc/2.0/ernievilg/v1/txt2imgv2?access_token=" + get_access_token()

    payload = json.dumps({
        "prompt": "长城",  # 输入中文描述
        "height": 1024,  # 选择图片分辨率，可支持1024*1024、1024*1536、1536*1024
        'width': 1024
    })
    headers = {
        'Content-Type': 'application/json',
        'Accept': 'application/json'
    }

    response = requests.request("POST", url, headers=headers, data=payload)

    print(response.text,type(response.text))
    url = "https://aip.baidubce.com/rpc/2.0/ernievilg/v1/getImgv2?access_token=" + get_access_token()
    # 发送请求获取网页内容
    payload = json.dumps({
        "task_id": response.text
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
    main1()

