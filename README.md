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
        + 