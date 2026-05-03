def agent(loc, status):
    if status == "Dirty":
        return "Suck"
    elif loc == "A":
        return "Right"
    else:
        return "Left"

# User input
loc = input("Enter location (A/B): ")
status = input("Enter status (Dirty/Clean): ")

print("Action:", agent(loc, status))