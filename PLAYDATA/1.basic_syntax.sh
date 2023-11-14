# 사용자가 현재 위치해 있는 폴더 경로 출력
pwd
# 현재 위치에서 파일, 폴더 목록
ls
# + 자세히
ls -l
# + 숨김 파일
ls -al
# 디렉토리 생성
mkdir jm_dir
# 특정 디렉토리로 이동
cd jm_dir
# 홈 디렉토리(/home/son)로 이동
cd
# 루트 디렉토리(최상위 디렉토리)로 이동
cd /
# 다시 기존의 폴더로 이동(절대 경로)
cd home/son/jm_dir
# 상위 폴더로 이동(상대 경로)
cd ..
# 이전에 있던 폴더로 이동
cd -

# 비어있는 파일 만들기
touch first_file.txtc
# 파일 내용 조회
cat first_file.txt
# 터미널창에 문자열 출력
echo "hello world"
# echo를 통해 파일에 write하는 방법
echo "hello world" > first_file.txt
# Ctrl + C = 명령어 삭제(무시하고 줄넘김)
# history 명령어를 통해 이전에 실행했던 명령어 조회
history
# 입력중인 명령창 정리
clear

# + nano 명령어를 통해 간단한 텍스트파일을 생성 및 수정할 수 있다.

# rm은 삭제명령어. rm -r은 디렉토리까지 삭제
# rm -rf는 디렉토리까지 묻지 않고 삭제
rm 파일명
rm -r 디렉토리명
rm -rf 디렉토리명

# cp는 복사명령어
# cp 복사대상 복사된파일명
cp first_file.txt second_file.txt
#cp -r 복사할디렉토리명 복사된디렉토리명
cp -r test_dir jm_dir/
# 상대경로 / 절대경로 두 가지 경우의 수 생각하기

# mv는 이동명령어 / 잘라내기와 같은 기능(-r 옵션 필요x)
# mv 이동대상 이동된파일명(경로포함)
mv test_dir jm_dir/second_dir

# head는 cat처럼 파일을 출력하는 명령어.
# head는 상위 10개 행 출력(default) -n 숫자 옵션을 주어 행 조절 가능
# tail은 하위 행 출력

# 리다이렉션(>, >>, |, < 등)의 의미
# echo는 터미널 화면에 출력하는 명령어
# echo와 > : 표준 출력의 결과를 덮어쓰기로 파일로 저장하는 기능
# echo와 >> : 표준 출력의 결과를 파일에 추가모드로 저장하는 기능
# sort와 < : 파일의 내용을 전달하여 정렬 후 출력
# |은 왼쪽 실행문의 결과값을 오른쪽 실행문의 입력값으로 전달