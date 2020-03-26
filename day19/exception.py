#%% (1) exception test
try :
    int(input("정수입력 : \n>>>"))

except Exception as e :
    print("정수를 입력하세요.")
#%% (2) exception test2

try :
    print(10/0)
except Exception as e :
    print("0으로 나눌 수 없습니다.")
finally :
#%% (3) my exception

class NicknameError(Exception) :
    pass

def checkNickname(nick) :
    if nick == "바보" :
        raise NicknameError


nickname = input("닉네임 : ")
try :
    checkNickname(nickname)
    print("닉네임 생성 성공")
except :
    print("비속어는 사용할 수 없습니다.")
    
#%% (3) exception task
#외부에서 채팅 문자열 받아와서
#in으로 비속어 검사를 한다.
#비속어는 바보, 멍청이, 똥개이다.
#사용자 예외처리로 선언하여 만든다.\
#비속어가 없다면 채팅 메시지를 출력한다.
chat = ''
    
class Badword(Exception) :
    pass

def checkBadword(word) :
    check = False
    
    badwordList = "바보,멍청,똥개".split(",")
    for i in badwordList :
        if i in word :
            #전역변수 수정 시 global로 선언 후 사용
            global chat
            chat = word.replace(i, "**")
            raise Badword
        

    

while True :
    inputMsg = input("문자 입력>>")

    try : 
        checkBadword(inputMsg)
    except :
        print(chat)
    if inputMsg == "1":
        break
        
    
    
    
    
    
    
    
    
    
    
    
    
    
        
    
    
    
    
    
    