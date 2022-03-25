# 진로 프로젝트

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
        + #### m_hWnd : 메인 윈도우의 핸들
        + #### m_ptResolution : 메인 윈도우의 해상도
    + ###  멤버 함수
        + #### init
            + #### 용도
                + #### 프로그램에 필요한 변수들을 초기화 해줌.
                + #### 윈도우의 크기를 지정한 사이즈로 변경 - 구현 예정
                + #### 매니저 클래스들을 초기화 시켜줌 - 구현 예정
                + #### 더블 버퍼링 적용 - 구현 예정 
        + #### progress
            + #### 용도
                + #### 물체 업데이트 및 렌더링 - 구현 예정
                + #### 매니저 클래스 업데이트 - 구현 예정
        
        + #### update
            + #### progress 내에서 업데이트 진행
        + #### render
            + #### progress 내에서 물체를 지정된 디바이스 컨텍스트에 렌더링함.


## Object 클래스
+ ### 용도 
    + ### 화면에 그려질 오브젝트 구성 정보 내장
    + 