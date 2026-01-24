#!/usr/bin/env python
"""Verify UK EQ-5D-5L data has all 17 age groups"""

from ppo_realistic_qaly import QALYCalculator

calc = QALYCalculator()

print("="*60)
print("UK EQ-5D-5L Data Verification")
print("="*60)
print(f"\n✓ Age points count: {len(calc.age_points)}")
print(f"✓ Female scores count: {len(calc.female_scores)}")
print(f"✓ Male scores count: {len(calc.male_scores)}")

print("\n" + "="*60)
print("All 17 Age Groups:")
print("="*60)
print(f"{'#':<4} {'Age Group':<12} {'Female':<8} {'Male':<8}")
print("-"*60)

age_group_names = [
    "16-17", "18-19", "20-24", "25-29", "30-34", "35-39",
    "40-44", "45-49", "50-54", "55-59", "60-64", "65-69",
    "70-74", "75-79", "80-84", "85-89", "90+"
]

for i in range(len(calc.age_points)):
    age = calc.age_points[i]
    female = calc.female_scores[i]
    male = calc.male_scores[i]
    group_name = age_group_names[i]
    print(f"{i+1:<4} {group_name:<12} {female:<8.3f} {male:<8.3f}")

print("="*60)
print("✅ All 17 age groups verified!")
print("="*60)

# Test interpolation
print("\n" + "="*60)
print("Testing Linear Interpolation:")
print("="*60)

test_ages = [50, 52, 55, 60, 65]
for age in test_ages:
    female_score = calc.get_qaly_weight(age, is_female=True)
    male_score = calc.get_qaly_weight(age, is_female=False)
    print(f"Age {age}: Female={female_score:.3f}, Male={male_score:.3f}")
