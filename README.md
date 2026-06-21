# CLI_RPG
## 빌드 및 실행 방법
### 1. 빌드 디렉토리 생성 및 이동
```bash
mkdir build
cd build
```
### 2. CMake 구성
```bash
cmake ..
```
### 3. 빌드
```bash
cmake --build .
```
### 4. 실행
#### 게임 실행
```bash
rpg.exe
```
#### 단위 테스트 실행
```bash
test.exe
```

## 주요 기능 사용법

### 새 게임 시작
1. 메인 메뉴에서 1. 새 게임 선택
2. 캐릭터 이름 입력
3. 직업 선택
   - 전사 (HP 150 / ATK 20 / DEF 15) — 강타로 데미지 1.5배
   - 마법사 (HP 90 / ATK 30 / DEF 5) — 방어력 무시 공격
   - 도적 (HP 100 / ATK 25 / DEF 8) — 30% 확률 급소 2배 데미지
   - 팔라딘 (HP 120 / ATK 18 / DEF 20) — 균형형 스탯

### 게임 루프 메뉴
| 번호 | 기능 |
|------|------|
| 1 | 모험 떠나기 (랜덤 몬스터와 전투) |
| 2 | 상태 확인 (캐릭터 스탯 + 인벤토리) |
| 3 | 저장 |
| 4 | 메인 메뉴로 |

### 전투
전투 중 매 턴마다 행동을 선택한다.

| 번호 | 행동 |
|------|------|
| 1 | 공격 |
| 2 | 아이템 사용 |
| 3 | 도망 |

- 승리 시 경험치 획득, 아이템 드롭(50% 확률), 자동 저장
- 패배 시 저장되지 않음
- 도망 시 자동 저장

### 저장 및 불러오기
- 저장 파일: save.txt (실행 파일과 같은 디렉토리에 생성)
- 저장 내용: 캐릭터 이름·직업·스탯·레벨·경험치·인벤토리
- 메인 메뉴에서 2. 불러오기 로 이어하기 가능

## 클래스 계층 구조
``` bash
Entity (추상 클래스)
├── Character
│   ├── Warrior
│   ├── Mage
│   ├── Rogue
│   └── Paladin
└── Monster
    ├── Slime
    ├── Goblin
    ├── Orc
    └── Dragon

Game
├── BattleSystem
├── SaveManager
└── Character*
        └── Inventory
                └── vector<Item>
```

## C++ 표준 예외 클래스 계층
``` bash
std::exception
├── std::logic_error        ← 프로그래머 실수로 인한 오류
│   ├── invalid_argument    ← 잘못된 인자
│   ├── out_of_range        ← 범위 초과
│   └── length_error        ← 길이 제한 초과
└── std::runtime_error      ← 실행 중 발생하는 오류
    ├── overflow_error      ← 산술 오버플로우
    └── underflow_error     ← 산술 언더플로우
```