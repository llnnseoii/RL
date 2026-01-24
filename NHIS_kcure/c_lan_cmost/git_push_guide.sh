#!/bin/bash
# GitHub 리포지토리에 코드 업로드하기
# 리포지토리: llnnseoii/RL

echo "========================================"
echo "Git 설정 및 GitHub 업로드 가이드"
echo "========================================"

# Step 1: Git 초기화
echo ""
echo "1️⃣ Git 리포지토리 초기화"
git init
git branch -M main  # 최신 GitHub는 main 브랜치 사용

# Step 2: 파일 추가 (.gitignore 먼저 생성)
echo ""
echo "2️⃣ 추가할 파일 선택"

# 먼저 .gitignore 생성 (불필요한 파일 제외)
cat > .gitignore << 'EOF'
# Python
__pycache__/
*.py[cod]
*$py.class
*.so
.Python
env/
venv/
*.egg-info/
dist/
build/

# Data files
*.pkl
*.pth
*.h5
*.npy

# Logs
*.log
runs/

# OS
.DS_Store
.obsidian/

# Outputs
output/
results/
EOF

echo "✓ .gitignore 생성 완료"

# 중요한 코드 파일만 추가
echo ""
echo "3️⃣ 파일 추가 (git add)"
git add ppo_realistic_qaly.py
git add qaly_calculator_updated.py
git add verify_eq5d.py
git add cql_optimizer.py
git add run_quality_pipeline.py
git add evaluate_cql.py
git add parameters.py
git add entities.py
git add output.py
git add .gitignore

# 또는 전체 추가 (주의: 큰 파일 있으면 제외)
# git add .

# Step 3: 커밋
echo ""
echo "4️⃣ 커밋 생성"
git commit -m "Add UK EQ-5D-5L based realistic QALY reward structure

- Integrated UK EQ-5D-5L population norms (17 age groups, gender-specific)
- Implemented realistic health economics reward: R = -Cost + QALY - Mortality
- Added QALY calculator with linear interpolation
- Updated PPO training with age/gender-specific QALY values
- Cancer stage utility decrements from Teckle et al. 2015
- WTP threshold: $50,000/QALY (Korean standard)"

# Step 4: GitHub 리모트 추가
echo ""
echo "5️⃣ GitHub 리포지토리 연결"
git remote add origin https://github.com/llnnseoii/RL.git

# Step 5: Push
echo ""
echo "6️⃣ GitHub에 업로드"
git push -u origin main

echo ""
echo "========================================"
echo "✅ 완료!"
echo "========================================"
echo ""
echo "리포지토리 주소: https://github.com/llnnseoii/RL"
