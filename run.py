import requests
import time

API_KEY = "iDxgiOHymWfgGyeVv6OsCwrNinu7X4t5"
SECRET = "LdUIuOuAjVF7xbe1wM0lVX6yFiMI1CTrx5nXVqjKOz04WrYu145QFkmijXFwfjlU"
BASE_URL = "https://ecoplas.tech"  

def listen_for_commands():
    last_command = None
    while True:
        try:
            res = requests.post(
                f"{BASE_URL}/getLogs",
                json={"apiKey": API_KEY, "secret": SECRET}
            )

            if res.status_code == 200:
                logs = res.json()

                if logs:
                    # Firebase stores logs as {logId: {payload, timestamp, status}}
                    latest_key = sorted(logs.keys())[-1]
                    latest_payload = logs[latest_key]["payload"]

                    if latest_payload != last_command:
                        last_command = latest_payload
                        print(f"New command received: {latest_payload}")
                else:
                    print("No commands yet.")
            else:
                print(f"Error: {res.status_code} - {res.text}")

        except Exception as e:
            print(f"Error connecting to server: {e}")

        time.sleep(2)  # poll every 2 seconds

if __name__ == "__main__":
    print("Starting ESP simulator...")
    listen_for_commands()
