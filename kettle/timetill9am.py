from datetime import datetime, timedelta

def how_many_seconds_until_9am():
    """Get the number of seconds until midnight."""
    tomorrow = datetime.now() + timedelta(1)
    midnight = datetime(year=tomorrow.year, month=tomorrow.month, 
                        day=tomorrow.day, hour=12, minute=28, second=0)
    return (midnight - datetime.now()).seconds

print(how_many_seconds_until_9am())
