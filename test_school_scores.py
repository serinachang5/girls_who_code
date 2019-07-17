import school_scores

def get_state_average(data, state_name):
    total_math_score = 0
    total_verbal_score = 0
    total_N = 0
    for record in data:
        if record["State"]["Name"] == state_name:
            avg_math = record["Total"]["Math"]
            avg_verbal = record["Total"]["Verbal"]
            N = record["Total"]["Test-takers"]
            total_math_score += avg_math * N
            total_verbal_score += avg_verbal * N
            total_N += N
    return total_math_score/total_N, total_verbal_score/total_N

def main():
    data = school_scores.get_all()
    state_name = "New York"  # edit to compute averages for another state
    math, verbal = get_state_average(data, state_name)
    print(state_name, "Math:", round(math, 3))
    print(state_name, "Verbal:", round(verbal, 3))

if __name__ == "__main__":
    main()
