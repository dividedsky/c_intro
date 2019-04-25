# input is an array of names
# outputs name with most votes
# in case of tie, return last alphabetical


def count_votes(names):
    # initialize table
    table = {}
    # winner
    winner = None
    # loop through the array
    # for each name
    for name in names:
        # if it's not in the table:
        if name not in table:
            # add name to table
            table[name] = 0

        # increment name by 1
        table[name] += 1
        if winner is None or table[name] > table[winner]:
            winner = name
        elif table[name] == table[winner]:
            if name > winner:
                winner = name
    return winner


print(
    count_votes(
        ["veronica", "mary", "alex", "james", "mary", "michael", "alex", "michael"]
    )
)
