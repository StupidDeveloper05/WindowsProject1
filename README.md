# 진로 프로젝트

[스케줄](https://github.com/StupidDeveloper05/WindowsProject1/blob/master/SCHEDULE.md)

## Core 클래스
+ ### 용도
    + ### 메인 윈도우에서 초기화 및 무한 루프에서 업데이트를 시켜줌.

+ ### 싱들톤으로 구성됨
    + #### 싱글톤이란?
        + #### 싱글톤은 클래스 생성자를 private으로 감추어서 함부로 객체를 생성 하도록 막는 구조이다.
        + #### 예제
        ```C++
        class SINGLETON
        {
        public:
            static SINGLETON GetInstance()
            {
                static SINGLETON instance;
                return & instance;
            }

        private:
            SINGLETON();
            ~SINGLETON();
        }

+ ### 멤버 변수 
    + m_hWnd : 메인 윈도우의 핸들
    + m_ptResolution : 메인 윈도우의 해상도
+ ###  멤버 함수
    + init
        + 용도
            + 프로그램에 필요한 변수들을 초기화 해줌.
            + 윈도우의 크기를 지정한 사이즈로 변경 
            + 매니저 클래스들을 초기화 시켜줌 
                + Key 매니저 초기화
                + Time 매니저 초기화
            + 더블 버퍼링 적용 
    + progress
        + 용도
            + 물체 업데이트 및 렌더링
            + 매니저 클래스 업데이트 
                + Key 매니저 업데이트
                + Time 매니저 업데이트



## Object 클래스
+ ### 용도 
    + ### 화면에 그려질 오브젝트 구성 정보 내장
    + ### 오브젝트 객체를 생성하고 업데이트 해줌

+ ### 멤버 함수
    + update 
        + 물체의 움직임과 같은 업데이트를 실행해줌. 
    + render
        + 물체를 화면 DC에 그려줌.


## Manager 클래스
+ ### KeyManager
    + ### 용도 :  키 입력을 관리해줌

+ ### TimeManager
    + ### 용도 :  델타 타임을 얻어와 줌.
    
