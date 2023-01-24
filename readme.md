# remotechest

A Particle project named remotechest. When an command is retrieved via the particle.io api open or close the 6V solenoid that locks or unlocks a chest. 


Create your particle.io token
CLI particle token create

The most common create a user access token is to use the Particle CLI particle token create command.

particle token create

Be sure to keep this token secure, because it allows access to your account and all of your devices. By default, the token will expire in 90 days and will need to be issued again. You can make a non-expiring token by using:

particle token create --never-expires


Test the API
Request:
curl https://api.particle.io/v1/devices/events -H "Authorization: Bearer <your token here>" -d "name=action" -d "data=open" -d "private=true" -d "ttl=60"
Response Body:
{"ok":true}


Request:
curl https://api.particle.io/v1/devices/events -v -H "Authorization: Bearer <your token here>" -d "name=action" -d "data=closed" -d "private=true"
Response Body:
{"ok":true}