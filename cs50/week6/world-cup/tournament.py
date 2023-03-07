# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    # Read teams into memory from file
    teams = []

    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)

        for row in reader:
            team_name = row['team']
            team_rating = int(row['rating'])
            teams.append({'team': team_name, 'rating': team_rating})

        #print(teams)

    # Simulate N tournaments and keep track of win counts
    counts = {}

    for i in range(N):
        winner = simulate_tournament(teams)

        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):                   # i iterates in step size of 2, to allow simulation of (i) vs (i + 1)
        if simulate_game(teams[i], teams[i + 1]):       # if team 1 wins
            winners.append(teams[i])                        # return winner as team 1
        else:                                           # else
            winners.append(teams[i + 1])                    # return winner as team 2

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    while len(teams) > 1:                               # while there is more than 1 team in the list
        teams = simulate_round(teams)                       # update teams list with list of winners
    return teams[0]["team"]                             # when 1 winner left, return 0th entry in the list, but specifically the value of the team column


if __name__ == "__main__":
    main()
